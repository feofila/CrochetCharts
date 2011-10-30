/*************************************************\
| Copyright (c) 2010 Stitch Works Software        |
| Brian C. Milco <brian@stitchworkssoftware.com>  |
\*************************************************/
#ifndef STITCH_H
#define STITCH_H

#include <QString>
#include <QList>
#include <QObject>

class QSvgRenderer;
class QPixmap;

class Stitch : public QObject
{
    friend class StitchSet;
    friend class TestStitch;
public:

    enum StitchParts { Name = 0, Icon, Description, Category, WrongSide };
    
    Stitch(QObject *parent = 0);
    ~Stitch();

    QString name() const { return mName; }
    QString file() const { return mFile; }
    QString description() const { return mDescription; }
    QString category() const { return mCategory; }
    QString wrongSide() const { return mWrongSide; }

    qreal width();
    qreal height();

    bool isSvg();

    QPixmap* renderPixmap();
    QSvgRenderer* renderSvg(bool useAltRenderer = false);

    //reload the svg with new colors.
    void reloadIcon();

    bool isBuiltIn;
    
protected:
    void setName(QString n) { mName = n; }
    void setFile(QString f);
    void setDescription(QString desc) { mDescription = desc; }
    void setCategory(QString cat) { mCategory = cat; }
    void setWrongSide(QString ws) { mWrongSide = ws; }
    
private:
    void setupSvgFiles();
    
    QString mName;
    QString mFile;
    QString mDescription;
    QString mCategory;
    QString mWrongSide;

    QSvgRenderer* mSvgRenderer;
    QSvgRenderer* mSvgRendererAlt;
    QPixmap* mPixmap;
};

#endif //STITCH_H
