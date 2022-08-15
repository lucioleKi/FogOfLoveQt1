#ifndef EVENTSIGNALS_H
#define EVENTSIGNALS_H

#include <QObject>

class EventSignals : public QObject
{
    Q_OBJECT
public:
    explicit EventSignals(QObject *parent = nullptr);

signals:

};

#endif // EVENTSIGNALS_H
