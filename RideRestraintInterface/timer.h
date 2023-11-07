#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
public:
    Timer();

private slots:
    void handleTimeout();

private:
    QTimer *timer;
};
