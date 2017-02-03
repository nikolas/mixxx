// wlibrarytableview.h
// Created 10/19/2009 by RJ Ryan (rryan@mit.edu)

#ifndef WLIBRARYTABLEVIEW_H
#define WLIBRARYTABLEVIEW_H

#include <QString>
#include <QTableView>
#include <QFont>

#include "preferences/usersettings.h"
#include "library/libraryview.h"
#include "track/track.h"
#include "library/coverartcache.h"


class WLibraryTableView : public QTableView, public virtual LibraryView {
    Q_OBJECT

  public:
    WLibraryTableView(QWidget* parent,
                      UserSettingsPointer pConfig,
                      ConfigKey vScrollBarPosKey);
    ~WLibraryTableView() override;
    void moveSelection(int delta) override;

    /**
     * @brief saveVScrollBarPos function saves current position of scrollbar
     * using string key - can be any value but should invariant for model
     * @param key unique for trackmodel
     */
    void saveVScrollBarPos(const QString key);
    /**
     * @brief restoreVScrollBarPos function finds scrollbar value associated with model
     * by given key and restores it
     * @param key unique for trackmodel
     */
    void restoreVScrollBarPos(const QString key);

  signals:
    void loadTrack(TrackPointer pTrack);
    void loadTrackToPlayer(TrackPointer pTrack, QString group,
            bool play = false);
    void trackSelected(TrackPointer pTrack);
    void onlyCachedCoverArt(bool);
    void scrollValueChanged(int);

  public slots:
    void saveVScrollBarPos(); // these slosts remain for compatibility
    void restoreVScrollBarPos();
    void setTrackTableFont(const QFont& font);
    void setTrackTableRowHeight(int rowHeight);

  private:
    void loadVScrollBarPosState();
    void saveVScrollBarPosState();

    QMap<QString, int> m_vScrollBarPosValues;

    UserSettingsPointer m_pConfig;
    ConfigKey m_vScrollBarPosKey;
    // The position of the vertical scrollbar slider, eg. before a search is
    // executed
    int m_iSavedVScrollBarPos;
};


#endif /* WLIBRARYTABLEVIEW_H */
