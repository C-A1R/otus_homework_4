#ifndef ISHAPE_H
#define ISHAPE_H

#include <iostream>


/**
 * @brief Интерфейс фигур
 */
class IShape
{
protected:
    bool _isValid {false}; ///< флаг показывает, достаточно ли данных (координат) для рисования
public:
    IShape() = default;
    virtual ~IShape() = default;

    /**
     * @brief Добавить координаты для рисования
     */
    virtual void addCoordinates(int x, int y) = 0;

    /**
     * @brief Рисовать фигуру
     */
    virtual void draw() const = 0;

    /**
     * @brief Если координат не достаточно для рисования, вернет false
     */
    bool isValid() const { return _isValid; } 
};

/**
 * @brief Точка
 */
class Point : public IShape
{
    int _x {0};
    int _y {0};
public:
    Point() = default;
    void addCoordinates(int x, int y) override
    {
        _x = std::move(x);
        _y = std::move(y);
        _isValid = true;
    }
    void draw() const override
    {
        if (!_isValid)
        {
            std::cerr << "DRAW: Point is invalid!" << std::endl;
            return;
        }
        std::cout << "DRAW: Point " << coordinates() << std::endl;
    }
    std::string coordinates() const
    {
        return "[" + std::to_string(_x) + ";" + std::to_string(_y) + "]";
    }
};

/**
 * @brief Прямая линия
 */
class Line : public IShape
{
    Point A;
    Point B;
public:
    Line() = default;
    void addCoordinates(int x, int y) override
    {
        if (!A.isValid())
        {
            A.addCoordinates(x, y);
        }
        else if (!B.isValid())
        {
            B.addCoordinates(x, y);
        }
        _isValid = A.isValid() && B.isValid();
    }
    void draw() const override
    {        
        if (!_isValid)
        {
            std::cerr << "DRAW: Line is invalid!" << std::endl;
            return;
        }
        std::cout << "DRAW: Line " 
                  << A.coordinates() << "-" 
                  << B.coordinates() << std::endl;
    }
};

/**
 * @brief Треугольник
 */
class Triangle : public IShape
{
    Point A;
    Point B;
    Point C;
public:
    Triangle() = default;
    void addCoordinates(int x, int y) override
    {
        if (!A.isValid())
        {
            A.addCoordinates(x, y);
        }
        else if (!B.isValid())
        {
            B.addCoordinates(x, y);
        }
        else if (!C.isValid())
        {
            C.addCoordinates(x, y);
        }
        _isValid = A.isValid() && B.isValid() && C.isValid();
    }
    void draw() const override
    {        
        if (!_isValid)
        {
            std::cerr << "DRAW: Triangle is invalid!" << std::endl;
            return;
        }
        std::cout << "DRAW: Triangle " 
                  << A.coordinates() << "-" 
                  << B.coordinates() << "-" 
                  << C.coordinates() << std::endl;
    }
};

#endif //ISHAPE_H