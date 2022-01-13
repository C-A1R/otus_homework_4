#include "IEditorView.h"

#include "IEditorModel.h"
#include "IEditorController.h"
#include "IShape.h"

GraphicView::GraphicView(const std::shared_ptr<IEditorModel> &model, 
            const std::shared_ptr<IEditorController> &controller)
    : _model{model}, _controller{controller}
{
}

void GraphicView::leftClick(int x, int y)
{
    _controller->addCoordinates(x, y);
}

void GraphicView::update()
{
    for (int i = 0; i < _model->getShapesCount(); ++i)
    {
        _model->getShape(i)->draw();
    }
}