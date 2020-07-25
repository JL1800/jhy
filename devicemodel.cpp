#include "devicemodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

DeviceModel::DeviceModel(QObject *parent, const QSqlDatabase &db) :
    QSqlQueryModel(parent),
    db_(db)
{
}

bool DeviceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool ok = false;
    if(index.column() < 1 || index.column() > 3)
    {
        return false;
    }

    // 获patientId对应的QModelIndex
    QModelIndex primaryIndex = QSqlQueryModel::index(index.row(),0);
    qDebug() << primaryIndex;

    // 获取对应行的patientId的值
    int devId = data(primaryIndex).toInt();

    if (index.column() == 1)
    {
        ok = this->setDerial(devId, value.toString());
    }

    if (index.column() == 2)
    {
        ok = this->setRefresh(devId, value.toString());
    }
//    if (index.column() == 3)
//    {
//        ok = this->setAge(patientId, value.toInt());
//    }
    if (ok)
    {
        this->setQuery("select * from device;");
    }
    else
    {
        qDebug() << "sql fail:";
    }
    return ok;

}

// 1、2、3列可编辑
Qt::ItemFlags  DeviceModel::flags(const QModelIndex &index) const
{
    // 获取index所在的flags
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2 || index.column() == 3)
    {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

bool DeviceModel::setDerial(int id, QString derial)
{
    QSqlQuery query(db_);
    query.prepare("update device set dev_derial=:derial where dev_id=:id;");
    query.bindValue(":dev_derial", derial);
    query.bindValue(":id", id);
//    if (!query.exec())
//    {
//        qDebug() << "error:" << query.lastError().text();
//        return false;
//    }
    return query.exec();
}

bool DeviceModel::setRefresh(int id, QString refresh)
{
    QSqlQuery query(db_);
    query.prepare("update patient set refresh=:refresh where dev_id=:id;");
    query.bindValue(":refresh", refresh);
    query.bindValue(":id", id);
    return query.exec();
}

//bool PatientModel::setAge(int id, int age)
//{
//    QSqlQuery query(db_);
//    query.prepare("update patient set age=:age where patientId=:id;");
//    query.bindValue(":age", age);
//    query.bindValue(":id", id);
//    return query.exec();
//}
