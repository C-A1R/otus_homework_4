#ifndef ISHAPEBTNCONTROLLER
#define ISHAPEBTNCONTROLLER


#include "IBtnController.h"
#include "IShape.h"

#include <memory>

/**
 * @brief Интерфейс контроллеров для кнопок рисования фигур
 * 
 */
class IShapeBtnCtrl : public IBtnController
{
    std::shared_ptr<IEditorController> _controller;
public:
    IShapeBtnCtrl(const std::shared_ptr<IEditorController> &controller) : _controller{controller}
    {
    }
    void exec() override
    {
        _controller->setCurrentShape(shape());
    }
    void cancel() override
    {
        _controller->setCurrentShape(nullptr);
    }
private:
    virtual std::unique_ptr<IShape> shape() = 0;
};

/**
 * @brief Рисовать точку
 */
class PointBtnCtrl : public IShapeBtnCtrl
{
public:
    PointBtnCtrl(const std::shared_ptr<IEditorController> &controller) : IShapeBtnCtrl(controller)
    {
    }
private:
    std::unique_ptr<IShape> shape() override
    {
        return std::make_unique<Point>();
    }
};

/**
 * @brief Рисовать линию
 */
class LineBtnCtrl : public IShapeBtnCtrl
{
public:
    LineBtnCtrl(const std::shared_ptr<IEditorController> &controller) : IShapeBtnCtrl(controller)
    {
    }
private:
    std::unique_ptr<IShape> shape() override
    {
        return std::make_unique<Line>();
    }
};

/**
 * @brief Рисовать треугольник
 */
class TriangleBtnCtrl : public IShapeBtnCtrl
{
public:
    TriangleBtnCtrl(const std::shared_ptr<IEditorController> &controller) : IShapeBtnCtrl(controller)
    {
    }
private:
    std::unique_ptr<IShape> shape() override
    {
        return std::make_unique<Triangle>();
    }
};

#endif //ISHAPEBTNCONTROLLER