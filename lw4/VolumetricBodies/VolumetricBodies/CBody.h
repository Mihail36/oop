#pragma once
#include "stdafx.h"

const int PRECISION = 10;

const std::string BODY_DENSITY = "Плотность = ";
const std::string BODY_VOLUME = "Объём = ";
const std::string BODY_MASS = "Масса = ";

const std::string TYPE_CONE = "Конус";
const std::string TYPE_CYLINDER = "Цилиндр";
const std::string TYPE_SPHERE = "Сфера";
const std::string TYPE_PARALLELEPIPED = "Параллелепипед";
const std::string TYPE_COMPOUND = "Составное тело";

const std::string APPEND_CONE_RADIUS = "Радиус основания = ";
const std::string APPEND_CONE_HEIGHT = "Высота конуса = ";

const std::string APPEND_CYLINDER_RADIUS = "Радиус основания = ";
const std::string APPEND_CYLINDER_HEIGHT = "Высота цилиндра = ";

const std::string APPEND_SPHERE_RADIUS = "Радиус = ";

const std::string APPEND_PARALLELEPIPED_WIDTH = "Ширина параллелепипеда = ";
const std::string APPEND_PARALLELEPIPED_DEPTH = "Длина параллелепипеда = ";
const std::string APPEND_PARALLELEPIPED_HEIGHT = "Высота параллелепипеда = ";

const std::string ERROR_EMPTY_COMPOUND = "Не удается рассчитать плотность для пустого составного тела";
const std::string ERROR_ALREADY_PART_OF_COMPOUND = "Тело уже является частью составного";
const std::string DIVIDER_STRING = "----------------";
const std::string NUMBER_OF_CHILD = "Дети: ";

class CBody
{
public:
	CBody();

	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0; 
	virtual double GetMass() const = 0;   
	virtual std::string GetType() const = 0;
	std::string ToString() const;

	virtual ~CBody();
private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
	std::string m_type;
};