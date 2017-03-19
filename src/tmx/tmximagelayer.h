#ifndef TMXIMAGELAYER_H
#define TMXIMAGELAYER_H

#include "tmxlayer.h"
#include <QPixmap>

#include <libtiled/tiled_imagelayer.h>

class TMXImageLayer : public TMXLayer
{
    Q_OBJECT

public:
    explicit TMXImageLayer(Tiled::TiledImageLayer *imageLayer, QObject *parent = 0)
        : TMXLayer(imageLayer, parent) , m_imageLayer(imageLayer) {}

    explicit TMXImageLayer(const TMXLayer &layer, QObject *parent = 0)
        : TMXLayer(layer.layer()->asImageLayer(), parent) , m_imageLayer(layer.layer()->asImageLayer()) {}

    Tiled::TiledImageLayer *tiledImageLayer() const { return m_imageLayer; }
    void setTiledImageLayer(Tiled::TiledImageLayer *imageLayer) { m_imageLayer = imageLayer; }

    QPixmap image() const { return m_imageLayer->image(); }
private:
    Tiled::TiledImageLayer *m_imageLayer;
};

#endif // TMXIMAGELAYER_H
