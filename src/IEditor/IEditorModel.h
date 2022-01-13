#ifndef IEDITORMODEL_H
#define IEDITORMODEL_H

#include <vector>
#include <memory>

class IEditorView;
class IShape;

/**
 * @brief Интерфейс модели
 */
class IEditorModel
{
public:
    IEditorModel() = default;
    virtual ~IEditorModel() = default;

    /**
     * @brief Установка представления
     */
    virtual void setView(const std::shared_ptr<IEditorView> &view) = 0;

    /**
     * @brief Добавление данных (фигур) в модель
     */
    virtual void addShape(std::unique_ptr<IShape> shape) = 0;

    /**
     * @brief Получить фигуру по индексу
     */
    virtual const IShape *getShape(int idnex) = 0;

    /**
     * @brief Количество фигур
     */
    virtual int getShapesCount() const = 0;
};

/**
 * @brief Модель для рисования
 */
class GraphicModel : public IEditorModel
{
    int shapesCount {0};
    std::shared_ptr<IEditorView> _view;
    std::vector<std::unique_ptr<IShape> > shapes;
public:
    GraphicModel() = default;
    virtual ~GraphicModel() = default;

    void setView(const std::shared_ptr<IEditorView> &view) override;
    void addShape(std::unique_ptr<IShape> shape) override;
    const IShape *getShape(int index) override;
    int getShapesCount() const override;
};

#endif //IEDITORMODEL_H