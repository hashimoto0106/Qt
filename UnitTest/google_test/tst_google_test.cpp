#include <QtTest>

// add necessary includes here

class google_test : public QObject
{
    Q_OBJECT

public:
    google_test();
    ~google_test();

private slots:
    void test_case1();

};

google_test::google_test()
{

}

google_test::~google_test()
{

}

void google_test::test_case1()
{

}

QTEST_APPLESS_MAIN(google_test)

#include "tst_google_test.moc"
