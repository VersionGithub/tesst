#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(FixAttemptsPlayLayer, PlayLayer) {
    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);

        // надпись "ATTEMPT N"
        auto label = m_attemptLabel;
        if (!label || !label->getParent()) return;

        // как надпись выглядит на экране с учётом поворотов/масштабов всех родителей
        // a < 0 -> отзеркалена по X, d < 0 -> отзеркалена по Y
        // поворот на 180° даёт сразу оба случая
        auto t = label->nodeToWorldTransform();

        if (t.a < 0.f) label->setScaleX(-label->getScaleX());
        if (t.d < 0.f) label->setScaleY(-label->getScaleY());
    }
};
