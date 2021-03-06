#ifndef PUSHDISPLAY_H
#define PUSHDISPLAY_H

#include <QObject>
#include <QScopedPointer>

class PushDisplayPrivate;

class PushDisplay : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(PushDisplay)
    Q_PROPERTY(bool dithering READ dithering WRITE setDithering NOTIFY ditheringChanged)

public:
    explicit PushDisplay(QObject *parent = 0);
    ~PushDisplay();
    bool isOpen() const;
    bool dithering() const;
    void setDithering(bool value);
    void drawImage(const QImage &image);
    QSize size() const;

signals:
    void ditheringChanged();

private:
    const QScopedPointer<PushDisplayPrivate> d_ptr;
};

#endif // PUSHDISPLAY_H
