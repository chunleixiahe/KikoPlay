#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QWidget>
#include <QTreeView>
class Aria2JsonRPC;
class QLabel;
class QPlainTextEdit;
class QStackedLayout;
class QButtonGroup;
class QSplitter;
struct DownloadTask;
class CTorrentFileModel;
class TorrentTreeView : public QTreeView
{
    Q_OBJECT
    Q_PROPERTY(QColor ignoreColor READ getIgnoreColor WRITE setIgnoreColor)
    Q_PROPERTY(QColor normColor READ getNormColor WRITE setNormColor)
public:
    using QTreeView::QTreeView;

    QColor getIgnoreColor() const {return ignoreColor;}
    void setIgnoreColor(const QColor& color)
    {
        ignoreColor =  color;
        emit ignoreColorChanged(ignoreColor);
    }
    QColor getNormColor() const {return normColor;}
    void setNormColor(const QColor& color)
    {
        normColor = color;
        emit normColorChanged(normColor);
    }
signals:
    void ignoreColorChanged(const QColor &color);
    void normColorChanged(const QColor &color);
private:
    QColor ignoreColor, normColor;
};

class BlockWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor fColor READ getFColor WRITE setFColor)
    Q_PROPERTY(QColor uColor READ getUColor WRITE setUColor)
public:
    BlockWidget(QWidget *parent = nullptr);

    QColor getBorderColor() const {return borderColor;}
    void setBorderColor(const QColor& color) { borderColor =  color; }
    QColor getFColor() const {return fillColorF;}
    void setFColor(const QColor& color) { fillColorF =  color; }
    QColor getUColor() const {return fillColorU;}
    void setUColor(const QColor& color) { fillColorU =  color; }

    void setBlock(int count, const QString &state);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
private:
    int blockWidth = 12*logicalDpiX()/96;
    int blockHeight = 12*logicalDpiY()/96;
    int marginX = 2*logicalDpiX()/96;
    int marginY = 2*logicalDpiY()/96;
    QColor borderColor, fillColorF, fillColorU;
    int blockCount = 0;
    QVector<int> blockState;
};

class DownloadWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DownloadWindow(QWidget *parent = nullptr);
    void beforeClose();
private:
    const int refreshInterval=1000;
    const int backgoundRefreshInterval=10000;

    QSplitter *contentSplitter;
    QTreeView *downloadView;
    QPlainTextEdit *logView;
    TorrentTreeView *fileInfoView;
    BlockWidget *blockView;
    CTorrentFileModel *selectedTFModel;
    QLabel *taskTitleLabel,*taskTimeLabel,*taskDirLabel;

    QAction *act_Pause,*act_Start,*act_Remove,*act_addToPlayList,
            *act_PauseAll,*act_StartAll,*act_BrowseFile,
            *act_CopyURI,*act_SaveTorrent;


    Aria2JsonRPC *rpc;
    DownloadTask *currentTask;

    QLabel *downSpeedLabel,*upSpeedLabel,*downSpeedIconLabel,*upSpeedIconLabel;
    QStackedLayout *rightPanelSLayout;
    QButtonGroup *taskTypeButtonGroup;
    QTimer *refreshTimer;

    QWidget *setupLeftPanel(QWidget *parent);
    QWidget *setupGeneralInfoPage(QWidget *parent);
    QWidget *setupFileInfoPage(QWidget *parent);
    QWidget *setupBlockPage(QWidget *parent);
    QWidget *setupGlobalLogPage(QWidget *parent);

    void initActions();
    void downloadSelectionChanged();
    void setDetailInfo(DownloadTask *task);
signals:
    void playFile(const QString &path);
protected:
    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);
};

#endif // DOWNLOADWINDOW_H
