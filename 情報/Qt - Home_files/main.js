"use strict";

function createCookie(name, value, days) {
    var expires;

    if (days) {
        var date = new Date();
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        expires = "; expires=" + date.toGMTString();
    } else {
        expires = "";
    }
    document.cookie = escape(name) + "=" + escape(value) + expires + "; path=/";
    $('.cookies_yum').click(function() {
        $(this).hide();
        $('body').removeClass('cookie-in-view');
    });
}

function readCookie(name) {
    var nameEQ = escape(name) + "=";
    var ca = document.cookie.split(';');
    for (var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ') c = c.substring(1, c.length);
        if (c.indexOf(nameEQ) === 0) return unescape(c.substring(nameEQ.length, c.length));
    }
    return null;
}

function eraseCookie(name) {
    createCookie(name, "", -1);
}


function load_sdk(s, id, src) {
    var js, fjs = document.getElementsByTagName(s)[0];
    if (document.getElementById(id)) return;
    js = document.createElement(s);
    js.id = id;
    js.src = src;
    fjs.parentNode.insertBefore(js, fjs);
}


//jQuery
$(document).ready(function($) {
	
    $(".in-page-nav a").on("click", function(e) {
        e.preventDefault();
        var b = $(this).attr("href");
        $("html, body").animate({
            scrollTop: $(b).offset().top
        }, 900);
    });

    // Lets move the links if needed
    if(document.documentElement.clientWidth < 1280){
        oneQt.extraLinksToMain();
    }
    oneQt.accordion();
    $('#menuextras .search').click(function(e){
        e.preventDefault();
        $('.big_bar.account').slideUp();
        $('.big_bar.search').slideToggle();
        $('.big_bar_search').focus();
        $(this).toggleClass('open');
    });
    //$('#menuextras .sign-in').click(function(e){
    //	e.preventDefault();
    //	$('.big_bar.search').slideUp();
    //	$('.big_bar.account').slideToggle();
    //});
    $('.cookies_yum').click(function() {
        $('.cookies_yum').hide();
        createCookie("cookies_nom", "yum", 180);
        $('body').removeClass('cookie-in-view');

        var cookie_added = 1;
    });
    if (!(readCookie('cookies_nom') == 'yum')){
        $('.cookies_yum').show();
        $('body').addClass('cookie-in-view');
    } else {
        var cookie_added = 1;
    }

    Modernizr.load({
        test: Modernizr.input.placeholder,
        nope: wpThemeFolder + '/js/placeholders.min.js'
    });

    //mobile nav
    $('#navbar .navbar-toggle').click(function(e) {
        e.preventDefault();
        //close mobile nav
        if($(this).hasClass('opened'))
        {
            $(this).removeClass('opened');
            $('#navbar .navbar-menu').css('max-height', '0px');
            //$('#navbar .navbar-menu').removeClass('opened');
        }
        //open mobile nav
        else
        {
            $(this).addClass('opened');
            $('#navbar .navbar-menu').css('max-height', $('#navbar .navbar-menu ul').outerHeight() + 'px');
            //$('#navbar .navbar-menu').addClass('opened');

        }
    });

    //set actions to be done after window resize
    $(window).resize(function() {
        //update "floating" sidebar
        oneQt.stickySidebar();
        //check if footer needs to be fixed to bottom
        oneQt.footerPosition();

        if(document.documentElement.clientWidth < 1280){
            oneQt.extraLinksToMain();
        } else {
            oneQt.mainLinkstoExtra();
        }

    });

    //set actions to be done on window scroll
    $(window).scroll(function() {
        //update "floating" sidebar
        oneQt.stickySidebar();
        //update floating mainmenu
        oneQt.stickyHeader();
    });

    //Create "floating" sidebar
    oneQt.stickySidebar();
    //check if footer needs to be fixed to bottom

    oneQt.footerPosition();

    //Create tabs
    oneQt.tabContents();
	
	//Smooth scroll for inpage nav
	oneQt.smoothScroll();

});

$( window ).load(function() {
    // Load dynamically after everything else has been loaded
    load_sdk('script', 'facebook-jssdk','//connect.facebook.net/en_US/sdk.js#xfbml=1&appId=207346529386114&version=v2.0');
    load_sdk('script', 'twitter-wjs', '//platform.twitter.com/widgets.js');

    // Load Google Feeds
    $.getScript("//www.google.com/jsapi", function(){
        google.load("feeds", "1", {"callback": oneQt.liveFeeds});
    });

    if($('.template-template-landingpage-php')){
        oneQt.landingpageHelpers();
    }

    if (!(readCookie('anim_seen') == 'da')){
        oneQt.timedHeaderAnimation();
        createCookie("anim_seen", "da", 180);
    } else {
        $('body').addClass('show-all-anim');
        $('[class*="cloud--"]').addClass('float');
    }
});


/**
 * oneQt main object
 */
var oneQt = {
    /**
     * create and update "floating" sidebar
     */
    stickySidebar: function() {
        if($('#sidebar').length && $('#sidebar').outerHeight() > 20) {
            var $sidebar = $('#sidebar');
            var $win = $(window);
            var $sidebarContainer = $sidebar.parent();
            var headerHeight = $('#navbar').outerHeight();
            //Set "fixed" position if needed
            if($win.outerHeight() - headerHeight > $sidebar.innerHeight() &&
                $win.scrollTop() > $sidebarContainer.offset().top)
            {
                //Check if sticky element's bottom is lower than its parent's bottom
                var newTop = headerHeight + $win.scrollTop() - $sidebarContainer.offset().top;
                if(newTop + $sidebar.innerHeight() > $sidebarContainer.innerHeight())
                    newTop = $sidebarContainer.innerHeight() - $sidebar.innerHeight();

                //set new position for sticky element
                $sidebar.css({
                    top: newTop +'px'
                })
            }
            else
            {
                //clear the "fixed" position
                $sidebar.css({
                    top: '0'
                })
            }
        }
    },

    /**
     * HEP! Accordion <3
     */

    accordion: function () {
        var accordionTrigger = $('.accordion-item').find('header');

        $(accordionTrigger).on('click', function () {

            $(this).parent().toggleClass('open');
        });
    },

    /**
     * Check if footer needs to be fixed to bottom
     */
    footerPosition: function () {
        $('#footerbar').removeClass('fixed');
        //If there is a hbspt form than don't try to adjust the stuff
        if (($('.hbspt-form').length > 0) || ($('#customerInfo').length > 0) || ($('.purchase_bar').length > 0)) {
            //get footer position
            var footerBottomPos = $('#footerbar').offset().top + $('#footerbar').outerHeight();
            //set fixed position if footer isn't at least at bottom of the screen
            if(footerBottomPos < $(window).height())
                $('#footerbar').addClass('fixed');
        }
    },

    /**
     * Update mainmenu layout according to window scroll position
     */
    stickyHeader: function () {
        var originalHeaderHeight = 79;
        //set sticky nav styles if page was scrolled more than original header height
        if($(window).scrollTop() > originalHeaderHeight) {
            $('#navbar').addClass('fixed');

            $('#bottom_header').fadeOut();

            if (!(cookie_added == 1)) {
                $('.cookies_yum').hide();
                $('body').removeClass('cookie-in-view');
                createCookie("cookies_nom", "yum", 180);
                var cookie_added = 1;
            }
        }
        else {
            $('#navbar').removeClass('fixed');
            $('#bottom_header').fadeIn();
        }
    },

    /**
     * Create "Tabs" content structure
    */
    tabContents: function () {

        //loop through all tab-containers
        $('.tab-container').each(function(i) {

            var hash = window.location.hash.substring(0); // Puts hash in variable with # character
            var $el = $(this);

            if( $el.find(hash).length ) { // Check if .tab-container have element with same ID as hash/#anchor
                // activate tab with #anchor
                $el.find('.tab-titles li' + hash).addClass('active');
                $el.find('.tab-contents ' + hash).addClass('active');
                // better viewport positioning
                var liHeight = $el.find('.tab-titles li:eq(0)').height();
                $('html,body').animate({scrollTop:$(hash).offset().top - liHeight}, 600);
            } else {
                // activate first tab
                $el.find('.tab-titles li:eq(0)').addClass('active');
                $el.find('.tab-contents .tab:eq(0)').addClass('active');
            }

            //bind click functions to change tab contents properly
            $el.find('.tab-titles a').click(function(e) {
                e.preventDefault();
                //get tab index number
                var index = $(this).parent().index();
                //clear active tab classes
                $el.find('.tab-titles li').removeClass('active');
                $el.find('.tab-contents .tab').removeClass('active');
                //set new active tab
                $(this).parent().addClass('active');
                $el.find('.tab-contents .tab').eq(index).addClass('active');
            })

        });
    },

    /**
     * This is callback function for Google Feeds
     * Always use "oneQt" notation instead of "this" inside this function
     */
    liveFeeds: function () {

        //Get blogfeeds
        $('.feed-container').each(function(i) {
            var feedUrl = $(this).data('url');
            if(feedUrl != "") oneQt.blogFeed($(this), feedUrl);
        });

    },

    /**
     * Get blog posts from RSS feeds
     * @param $container {jQuery object}
     * @param $feedUrl {String}
     */
    blogFeed: function ($container, feedUrl) {
        //set feed url
        var feed = new google.feeds.Feed(feedUrl);
        //limit fetched entries
        feed.setNumEntries(3);
        //load feed
        feed.load(function(result) {
            //delete loading image
            $container.html('');
            if (!result.error) {
                //loop through entries
                for (var i = 0; i < result.feed.entries.length; i++) {

                    var entry = result.feed.entries[i];
                    //create container for entry
                    var $article = $('<article class="discussion-tile cf"></article>');
                    //append entry container to main feed container
                    $container.append($article);
                    //create html template for entry
                    var html = '	<div class="discussion-item">';
                    html += '   	<h4><a href="'+encodeURI(entry.link)+'"></a></h4>'
                    html += '		<h3><a href="'+encodeURI(entry.link)+'" target="_blank"></a></h3>'
                    html += '		<span><a href="'+encodeURI(entry.link)+'" target="_blank"></a></span>';
                    //html += '		<ul class="taglist cf">';
                    //html += '		</ul>';
                    html += '	</div>';
                    //append html template to entry container
                    $article.append(html);
                    //put entry contents to entry template
                    $article.find('h4 a').text(result.feed.title);
                    $article.find('h3 a').text(entry.title);
                    $article.find('span a').text(entry.author);
                    //try to loop through entry categories
                    //try {
                    //	for(var j=0; j<entry.categories.length; j++) {
                    //		//create li element
                    //		var $li = $('<li><a href="'+encodeURI(entry.link)+'" target="_blank" class="btn btn-tag"></a></li>');
                    //		//put category name to li element
                    //		$li.find('a').text(entry.categories[j]);
                    //		//append li element to tag list
                    //		$article.find('.taglist').append($li);
                    //
                    //	}
                    //
                    //} catch(e) {}
                }
                //put "show all" link on the bottom if feed has a link
                if(result.feed.link && result.feed.link != "") {
                    var linkHtml = '<a href="'+encodeURI(result.feed.link)+'" class="text-lightgrey" target="_blank">Show all</a>';
                    $container.append(linkHtml);
                }
            }

        });
    },
    extraLinksToMain: function(){

        // Lets move the links, depending on resolution
        var extramenuLinks = $('#menuextras').find('li');
        var mainmenu = $('#mainmenu');
        var count = 0;

        if($(extramenuLinks).length > 3){
            $(extramenuLinks).each(function(){

                if(count < 3){

                    var newLink = $(this);

                    $(newLink).addClass('dynamic-add');

                    $(mainmenu).append(newLink);

                }

                count++;

            });
        }


    },
    mainLinkstoExtra: function(){

        // Lets move the links, depending on resolution
        var mainmenuLinks = $('#mainmenu').find('.dynamic-add');
        var extramenu = $('#menuextras');
        var searchLink = $('li.search');
        var count = 0;

        $(mainmenuLinks).each(function(){

            var newLink = $(this);

            $(searchLink).before(newLink);

            count++;

        });
    },

    // Something for the landing, respectively
    landingpageHelpers: function () {

        $(".carousel").owlCarousel({
            items: 1,
            itemsDesktop: false,
            itemsDesktopSmall: [979,1],
            itemsTablet: [768,1]

        });

        // Get the instance of our carousel!
        var lpCarousel = $('.carousel').data('owlCarousel');

        if($('.page-template-template-landingpage-php').length){


            $('.slider-next-slide').on('click', function (e) {
                e.preventDefault();

                lpCarousel.next();
            });

        }
    },
    isVisible: function (el) {

        if (typeof jQuery === "function" && el instanceof jQuery) {
            el = el[0];
        }

        var rect = el.getBoundingClientRect();

        return (
        rect.top >= 0 &&
        rect.left >= 0 &&
        rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) && /*or $(window).height() */
        rect.right <= (window.innerWidth || document.documentElement.clientWidth) /*or $(window).width() */
        );
    },
    timedHeaderAnimation: function () {
        $('.animated-sub-content').addClass('visible');

        setTimeout(function () {
            $('.first-phase').addClass('to-top');
        }, 2000);

        setTimeout(function () {
            $('.in-between').addClass('disappear');
        }, 4000);

        setTimeout(function () {
            $('[class*="cloud--"]').addClass('float');
        }, 7300);

        setTimeout(function () {
            $('.third-phase.two').addClass('pulse');
        }, 8800);
    },
	smoothScroll: function () {

		$('#pagenav a[href^="#"]').on('click',function (e) {
			
			e.preventDefault();
			
			var topPosition = 90;
	
			var target = this.hash,
			$target = $(target);
			
			// CHECK IF USER HAVE LUMIA......
			
			var isMobile = { 
				Windows: function() { 
					return navigator.userAgent.match(/IEMobile/i); 
				},
				any: function() { 
					return ( isMobile.Windows() ); 
				}
			};
	
			if( isMobile.Windows() ) {
				$('html').scrollTop($target.offset().top - topPosition); // FOR LUMIA
			} else {
				$('html, body').stop().animate({ 'scrollTop': $target.offset().top - topPosition }, 900, 'swing', function () {}); // FOR OTHERS
			}
			
		});
	}

}

$(window).on('DOMContentLoaded, load, resize, scroll',function(){

    if($('.page-template-template-landingpage-php').length){
        var devices = oneQt.isVisible($('.slide-to-view'));
        var parallaxEl = document.querySelectorAll('.parallaxIMG');

        if(devices){
            if($('.slide-to-view').hasClass('stacked')){
                // $('.slide-to-view').removeClass('stacked');
            }
        }


        for(var i=0; i<parallaxEl.length; i++){
            var a = document.documentElement.scrollTop || document.body.scrollTop;
            var c = $(parallaxEl[i]).offset().top;

            var d = c-a;
            var b = -d*0.2;

            $(parallaxEl[i]).css({
                '-webkit-transform' : 'translate3d(0,' + b +'px'+',0)',
                '-moz-transform' : 'translate3d(0,' + b +'px'+',0)',
                'transform' : 'translate3d(0,' + b +'px'+',0)'
            });

        }
    }

});
