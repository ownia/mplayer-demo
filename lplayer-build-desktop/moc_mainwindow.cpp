/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lplayer/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0next()\0prev()\0pause()\0"
    "stop()\0setSpeed()\0dataRecieve()\0"
    "addItem()\0delItem()\0current(int)\0"
    "changeVolume(int)\0playListItem(QListWidgetItem*)\0"
    "buttonClicked()\0exit()\0sql_list()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->prev(); break;
        case 2: _t->pause(); break;
        case 3: _t->stop(); break;
        case 4: _t->setSpeed(); break;
        case 5: _t->dataRecieve(); break;
        case 6: _t->addItem(); break;
        case 7: _t->delItem(); break;
        case 8: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->playListItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->buttonClicked(); break;
        case 12: _t->exit(); break;
        case 13: _t->sql_list(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
