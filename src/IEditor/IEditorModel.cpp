#include "IEditorModel.h"

#include "IEditorView.h"
#include "../IShape.h"


void GraphicModel::setView(const std::shared_ptr<IEditorView> &view)
{
    _view = view;
}

void GraphicModel::addShape(std::unique_ptr<IShape> shape)
{
    shapes.emplace_back(std::move(shape));
    ++shapesCount;
    _view->update();
}

const IShape *GraphicModel::getShape(int index)
{
    if (index < 0 || index > shapesCount)
    {
        return nullptr;
    }
    return shapes[index].get();
}

int GraphicModel::getShapesCount() const
{
    return shapesCount;
}