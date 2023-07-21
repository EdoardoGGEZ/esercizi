#pragma once

#define CLOCKOBJECT_H

#include <QAbstractListModel>

struct AlarmData{
    QString dateTime;
    bool isActive;
};

class ClockObject : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        dateTime = Qt::UserRole + 1,
        isActive,
    };
    ClockObject();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE void addAlarm(QString time, bool active);
private:
    QVector<AlarmData> alarms;
};
