#pragma once
#include "stdafx.h"
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

const std::string COMMAND_ADD_BODY = "1";
const std::string COMMAND_GET_MAX_MASS_BODY = "2";
const std::string COMMAND_GET_LIGHTEST_BODY_IN_WATER = "3";
const std::string COMMAND_GET_INFO_ABOUT_ALL_BODIES = "4";

const int TYPE_BODY_SHPERE = 1;
const int TYPE_BODY_PARALLELEPIPED = 2;
const int TYPE_BODY_CONE = 3;
const int TYPE_BODY_CYLINDER = 4;
const int TYPE_BODY_COMPOUND = 5;

const char RUSSIAN_LANGUAGE[8] = "Russian";
const char LINE_BREAK = '\n';

const std::string MESSAGE_INCORRECT_COMMAND = "Неверная команда!\n";
const std::string MESSAGE_NUMBER_COMMAND = "Номер команды: ";

const double WATER_DENSITY = 1000;
const double ACCELERATION_OF_FREE_FALL = 9.806;

const std::string ENTER_RADIUS_SPHERE = "Введите радиус сферы: ";
const std::string ENTER_DENSITY_SPHERE = "Введите плотность сферы: ";

const std::string ENTER_WIDTH_PARALLELEPIPED = "Введите ширину параллелепипеда: ";
const std::string ENTER_DEPTH_PARALLELEPIPED = "Введите длину параллелепипеда: ";
const std::string ENTER_HEIGHT_PARALLELEPIPED = "Введите высоту параллелепипеда: ";
const std::string ENTER_DENSITY_PARALLELEPIPED = "Введите плотность параллелепипеда: ";

const std::string ENTER_BASE_RADIUS_CONE = "Введите радиус основания конуса: ";
const std::string ENTER_HEIGHT_CONE = "Введите высоту конуса: ";
const std::string ENTER_DENSITY_CONE = "Введите плотность конуса: ";

const std::string ENTER_BASE_RADIUS_CYLINDER = "Введите радиус основания цилиндра: ";
const std::string ENTER_HEIGHT_CYLINDER = "Введите высоту цилиндра: ";
const std::string ENTER_DENSITY_CYLINDER = "Введите плотность цилиндра: ";

const std::string ENTER_NUMBER_OF_BODIES = "Введите количество тел, которое должно находиться в составном теле: ";
const std::string ENTER_NUMBER_OF_CHILD = "Введите количество детей: ";
const std::string MESSAGE_ABOUT_TYPE_BODY = "\nВведите тип тела \n1 - Сфера\n2 - Параллелепипед\n3 - Конус\n4 - Цилиндр\n5 - Составное тело\n\n";
const std::string UNKNOWN_BODY_TYPE = "Неизвестный тип тела\n";
const std::string ENTER_TYPE_BODY = "Тип тела: ";
const std::string FIRST_PART_DIVISION = "-------";
const std::string SECOND_PART_DIVISION = "-------\n";
const std::string START_MESSAGE = "------- Доступные команды------- \n1 - Добавить тело\n2 - Найти тело с наибольшей массой\n3 - Найти тело которое будет легче всего весить, будучи полностью погруженным в воду\n4 - Вывести информацию обо всех телах\n\n";

const std::string BODY_SUCCESSFULLY_ADDED = "Тело успешно добавлено!";
const std::string CHILD_SUCCESSFULLY_ADDED = " успешно добавлено!";
const std::string OUT_OF_MESSAGE = " из ";
const std::string ERROR_NUMBER_OF_CHILD_NEGATIVE = "Количество детей должно быть положительным числом!";
const std::string ERROR_VALUE_NEGATIVE = "Значения не могут быть отрицательными!";
const std::string ERROR_BODIES_ABSENT = "Тела отсутствуют!";
const std::string ERROR_VALUE_NOT_DIGIT = "Ошибка ввода! Значение должно быть цифрой!";
const std::string INCORRECT_COMMAND = "Неверная команда!";



class CController
{
public:
	CController(std::istream &input, std::ostream &output, std::vector<std::shared_ptr<CBody>>& bodies);
	~CController();
	void ProcessInput();

private:
	bool HandleCommand();
	bool SetNewBody();
	bool GetInfoAboutAllBodies() const;
	bool GetMaxMassBody() const;
	bool GetLightestBodyInWater() const;
	bool GetInfoAboutBody(const std::shared_ptr<CBody>& body) const;
	double GetWeightBodyInWater(const std::shared_ptr<CBody>& body) const;
	double SetValueDouble(const std::string& prompt);

	std::shared_ptr<CBody> SetBody(int type);
	std::shared_ptr<CBody> SetSphere();
	std::shared_ptr<CBody> SetParallelepiped();
	std::shared_ptr<CBody> SetCone();
	std::shared_ptr<CBody> SetCylinder();
	std::shared_ptr<CBody> SetCompound();

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;
	std::vector<std::shared_ptr<CBody>>& m_bodies;

	const ActionMap m_actionMap;
};