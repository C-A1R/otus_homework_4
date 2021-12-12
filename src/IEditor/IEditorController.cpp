#include "IEditorController.h"

#include "IEditorModel.h"
#include "../IShape.h"


GraphicController::GraphicController(const std::shared_ptr<IEditorModel> &model) : _model{model}
{
}

void GraphicController::setCurrentShape(std::unique_ptr<IShape> shape)
{
    _currentShape = std::move(shape);
}

void GraphicController::addCoordinates(int x, int y)
{
    if (nullptr == _currentShape)
    {
        return;
    }
    _currentShape->addCoordinates(x, y);
    if (_currentShape->isValid())
    {
        _model->addShape(std::move(_currentShape));
        _currentShape = nullptr;
    }
}