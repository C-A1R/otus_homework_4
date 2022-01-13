#ifndef IEDITORCONTROLLER
#define IEDITORCONTROLLER

#include <memory>

class IEditorModel;
class IShape;

/**
 * @brief Интерфейс контроллера для рисования
 */
class IEditorController
{
public:
    IEditorController() = default;
    virtual ~IEditorController() = default;

    /**
     * @brief Устанавливает выбранную для рисования фигуру
     */
    virtual void setCurrentShape(std::unique_ptr<IShape> shape) = 0;

    /**
     * @brief Считываение координат клика по виджету
     */
    virtual void addCoordinates(int x, int y) = 0;
};

/**
 * @brief Контроллер для рисования
 */
class GraphicController : public IEditorController
{
    std::shared_ptr<IEditorModel> _model;
    std::unique_ptr<IShape> _currentShape; ///<выбранная для рисования фигура

public:
    GraphicController(const std::shared_ptr<IEditorModel> &model);
    ~GraphicController() override = default;

    void setCurrentShape(std::unique_ptr<IShape> shape) override;
    void addCoordinates(int x, int y) override;
};

#endif //IEDITORCONTROLLER