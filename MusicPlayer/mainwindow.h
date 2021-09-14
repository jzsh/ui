#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
private slots:
    void tick(qint64 time);
	void _connectSlots();
    void stateChanged(Phonon::State newState, Phonon::State /* oldState */);
    void sourceChanged(const Phonon::MediaSource &source);
    void aboutToFinish();
private:
    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *m_mediaObject;
    Phonon::MediaObject *metaInformationResolver;
    Phonon::AudioOutput *audioOutput;
    Phonon::VolumeSlider *volumeSlider;
    QList<Phonon::MediaSource> sources;
	
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
