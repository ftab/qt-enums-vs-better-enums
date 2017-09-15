#include <iostream>
#include <iomanip>
#include <QCoreApplication>
#include <QMetaEnum>
#include <QDebug>
#include "color.h"
using namespace std;
using namespace Color;

void SingWithQ_ENUM(void)
{
    /* Let's play with Q_ENUM_NS / QMetaEnum.
     * Note that Qt Creator colors the text and
     * autocompletes if it's changed */
    Primary mycolor = Primary::Blue;

    qDebug() << "I'm" << mycolor << "daba-dee daba-die";

    qDebug() << "I'm" << QMetaEnum::fromType<Primary>()
                         .valueToKey((int)mycolor)
             << "daba-dee daba-die";

    cout << "I'm " << setfill('0') << setw(6) << hex << mycolor
         << " daba-dee daba-die" << endl;

    cout << "I'm " << QMetaEnum::fromType<Primary>()
                      .valueToKey((int)mycolor)
         << " daba-dee daba-die" << endl;

    /* Now iterate over all enums in Color */
    QMetaObject meta = Color::staticMetaObject;
    for (int i=0; i < meta.enumeratorCount(); ++i) {
        QMetaEnum m = meta.enumerator(i);
        qDebug() << m.name() << ":";
        for (int x = 0; x < m.keyCount(); x++)
        {
            cout << "\t" << m.key(x) << "\t=\t"
                 << setfill('0') << setw(6) << m.value(x) << endl;
        }
    }
    /* Q_ENUM_NS / QMetaEnum section output:

        I'm Color::Primary(Blue) daba-dee daba-die
        I'm Blue daba-dee daba-die
        I'm 0000ff daba-dee daba-die
        I'm Blue daba-dee daba-die
        Primary :
                Red     =       ff0000
                Green   =       00ff00
                Blue    =       0000ff
     */
}

void SingWithBetterEnums(void)
{
    /* Now let's try better-enums. Note that Qt Creator
       does not color or auto complete. */
    Secondary othercolor = Secondary::Yellow;

    cout << "We all live in a " << othercolor
         << " submarine, a " << othercolor._to_string()
         << " submarine, a " << hex << othercolor._to_integral()
         << " submarine" << endl;

    /* and iterate: */
    for (size_t index = 0; index < Secondary::_size(); ++index) {
        Secondary thiscolor = Secondary::_values()[index];
        cout << "\t" << thiscolor
             << "\t=\t" << setfill('0') << setw(6) << thiscolor._to_integral()
             << endl;
    }
    /* better-enums section output:

        We all live in a Yellow submarine, a Yellow submarine, a ffff00 submarine
                Cyan    =       00ffff
                Magenta =       ff00ff
                Yellow  =       ffff00

     */
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SingWithQ_ENUM();
    SingWithBetterEnums();

    return a.exec();
}
