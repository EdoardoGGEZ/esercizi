#include "clockobject.h"

ClockObject::ClockObject(){
    alarms = {
        {
            "7:00",
            true,
        },
        {
            "18:05",
            false,
        },
    };
}

QVariant ClockObject::data(const QModelIndex &index, int role) const
{
    int ind = index.row();
    AlarmData alarm = alarms[ind];
    switch(role)
    {
    case dateTime:
        return alarm.dateTime;
    case isActive:
        return alarm.isActive;
    default:
        return QVariant();
    }
}

int ClockObject::rowCount(const QModelIndex &parent) const
{
    return alarms.count();
}

QHash<int, QByteArray> ClockObject::roleNames() const
{
    return {
        {dateTime, "dateTime"},
        {isActive, "isActive"},
        };
}

void ClockObject::addAlarm(QString time, bool active)
{
    alarms.append({time, active});
}
