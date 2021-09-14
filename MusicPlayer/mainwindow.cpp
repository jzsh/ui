#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    // media object
	m_mediaObject = new Phonon::MediaObject(this);
	
	Phonon::MediaSource* source = new Phonon::MediaSource("H:/CloudMusic/Alan Walker - Faded.mp3");
	m_mediaObject->setCurrentSource(*source);
    m_mediaObject->setTickInterval(200);
	
	Phonon::Path path = Phonon::createPath(m_mediaObject, audioOutput);
	
	_connectSlots();
	// plaing
    m_mediaObject->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::_connectSlots()
{
    connect(m_mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(m_mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(m_mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(m_mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));
}

void MainWindow::tick(qint64 time)
{
    float percent = time*100/m_mediaObject->totalTime();
    qDebug() << int(percent) << "%";
}

void MainWindow::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{

}

void MainWindow::sourceChanged(const Phonon::MediaSource &source)
{

}

void MainWindow::aboutToFinish()
{

}
