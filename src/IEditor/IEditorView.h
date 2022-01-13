#ifndef IEDITORVIEW_H
#define IEDITORVIEW_H

#include <memory>

class IEditorModel;
class IEditorController;

/**
 * @brief Интерфейс виджета для рисования
 */
class IEditorView
{
public:
    IEditorView() = default;
    virtual ~IEditorView() = default;

    /**
     * @brief Имитация клика по виджету в точке с координатами [x;y]
     */
    virtual void leftClick(int x, int y) = 0;

    /**
     * @brief Перерисовка
     */
    virtual void update() = 0;
};

/**
 * @brief Виджет для рисования
 */
class GraphicView : public IEditorView
{
    std::shared_ptr<IEditorModel> _model;
    std::shared_ptr<IEditorController> _controller;
public:
    GraphicView(const std::shared_ptr<IEditorModel> &model, 
                const std::shared_ptr<IEditorController> &controller);

    void leftClick(int x, int y) override;
    void update() override;
private:
    void clear();
};

#endif //IEDITORVIEW_H