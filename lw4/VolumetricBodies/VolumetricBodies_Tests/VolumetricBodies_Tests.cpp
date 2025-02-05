#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../VolumetricBodies/CBody.h"
#include "../VolumetricBodies/CCone.h"
#include "../VolumetricBodies/CController.h"
#include "../VolumetricBodies/CCylinder.h"
#include "../VolumetricBodies/CParallelepiped.h"
#include "../VolumetricBodies/CSolidBody.h"
#include "../VolumetricBodies/CSphere.h"
#include "../VolumetricBodies/stdafx.h"

TEST_CASE("Test CCone class")
{
	SECTION("Test GetVolume - correct")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * (height / 3);

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetVolume() == expectedVolume);
		std::cout << "Test CCone class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - base radius equal zero")
	{
		double baseRadius = 0.0;
		double height = 3.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * (height / 3);

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetVolume() == expectedVolume);
		std::cout << "Test CCone class (GetVolume - base radius equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		std::string expectedType = "Конус";

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.GetType() == expectedType);
		std::cout << "Test CCone class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double baseRadius = 2.0;
		double height = 3.0;
		double density = 1.0;
		std::string expectedType = "Конус";

		CCone cone(baseRadius, height, density);
		REQUIRE(cone.ToString() == "Конус\nПлотность = 1\nОбъём = 12.56637061\nМасса = 12.56637061\nРадиус основания = 2\nВысота конуса = 3\n");
		std::cout << "Test CCone class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}

TEST_CASE("Test CCylinder class")
{
	SECTION("Test GetVolume - correct")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * height;

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetVolume() == expectedVolume);
		std::cout << "Test CCylinder class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - height equal zero")
	{
		double baseRadius = 3.0;
		double height = 0.0;
		double density = 5.0;
		double expectedVolume = M_PI * pow(baseRadius, 2) * height;

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetVolume() == expectedVolume);
		std::cout << "Test CCylinder class (GetVolume - height equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		std::string expectedType = "Цилиндр";

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.GetType() == expectedType);
		std::cout << "Test CCylinder class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double baseRadius = 3.0;
		double height = 1.0;
		double density = 1.0;
		std::string expectedType = "Цилиндр";

		CCylinder cylinder(baseRadius, height, density);
		REQUIRE(cylinder.ToString() == "Цилиндр\nПлотность = 1\nОбъём = 28.27433388\nМасса = 28.27433388\nРадиус основания = 3\nВысота цилиндра = 1\n");
		std::cout << "Test CCylinder class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}


TEST_CASE("Test CParallelepiped class")
{
	SECTION("Test GetVolume - correct")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		double expectedVolume = width * height * depth;

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetVolume() == expectedVolume);
		std::cout << "Test CParallelepiped class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - depth and width equal zero")
	{
		double width = 0.0;
		double height = 1.0;
		double depth = 0.0;
		double density = 3.0;
		double expectedVolume = width * height * depth;

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetVolume() == expectedVolume);
		std::cout << "Test CParallelepiped class (GetVolume - depth and width equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		std::string expectedType = "Параллелепипед";

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.GetType() == expectedType);
		std::cout << "Test CParallelepiped class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double width = 3.0;
		double height = 1.0;
		double depth = 4.0;
		double density = 1.0;
		std::string expectedType = "Параллелепипед";

		CParallelepiped parallelepiped(width, depth, height, density);
		REQUIRE(parallelepiped.ToString() == "Параллелепипед\nПлотность = 1\nОбъём = 12\nМасса = 12\nШирина параллелепипеда = 3\nДлина параллелепипеда = 4\nВысота параллелепипеда = 1\n");
		std::cout << "Test CParallelepiped class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}



TEST_CASE("Test CSphere class")
{
	SECTION("Test GetVolume - correct")
	{
		double radius = 2.0;
		double density = 1.0;
		double expectedVolume = (4 / 3) * (M_PI * pow(radius, 3));

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetVolume() == expectedVolume);
		std::cout << "Test CSphere class (GetVolume - correct) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - radius equal zero")
	{
		double radius = 0.0;
		double density = 1.0;
		double expectedVolume = (4 / 3) * (M_PI * pow(radius, 3));

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetVolume() == expectedVolume);
		std::cout << "Test CSphere class (GetVolume - radius equal zero) - Completed" << std::endl;
	}

	SECTION("Test GetType")
	{
		double radius = 2.0;
		double density = 1.0;
		std::string expectedType = "Сфера";

		CSphere sphere(radius, density);
		REQUIRE(sphere.GetType() == expectedType);
		std::cout << "Test CSphere class (GetType) - Completed" << std::endl;
	}

	SECTION("Test AppendProperties")
	{
		double radius = 2.0;
		double density = 1.0;
		std::string expectedType = "Сфера";

		CSphere sphere(radius, density);
		REQUIRE(sphere.ToString() == "Сфера\nПлотность = 1\nОбъём = 25.13274123\nМасса = 25.13274123\nРадиус = 2\n");
		std::cout << "Test CSphere class (AppendProperties) - Completed" << std::endl << std::endl;
	}
}
TEST_CASE("Test CCompound class")
{
	SECTION("Test GetDensity - Empty compound body throws exception")
	{
		CCompound compound;
		REQUIRE_THROWS_AS(compound.GetDensity(), std::logic_error);
		std::cout << "Test CCompound class (GetDensity - Empty compound body throws exception) - Completed" << std::endl;
	}

	SECTION("Test GetDensity - Compound body with children calculates density correctly")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CSphere>(3.0, 2.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCylinder>(2.0, 2.0, 1.0);

		compound.AddChild(child1);
		compound.AddChild(child2);

		double expectedDensity = ((child1->GetMass() + child2->GetMass()) / (child1->GetVolume() + child2->GetVolume()));
		REQUIRE(compound.GetDensity() == Approx(expectedDensity));
		std::cout << "Test CCompound class (GetDensity - Compound body with children calculates density correctly) - Completed" << std::endl;
	}


	SECTION("Test GetVolume - Compound body with no children has zero volume")
	{
		CCompound compound;
		REQUIRE(compound.GetVolume() == 0.0);
		std::cout << "Test CCompound class (GetVolume - Compound body with no children has zero volume) - Completed" << std::endl;
	}

	SECTION("Test GetVolume - Compound body with children calculates volume correctly")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CSphere>(1.0, 3.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCylinder>(2.0, 2.0, 2.0);

		compound.AddChild(child1);
		compound.AddChild(child2);

		double expectedVolume = child1->GetVolume() + child2->GetVolume();
		REQUIRE(compound.GetVolume() == Approx(expectedVolume));
		std::cout << "Test CCompound class (GetVolume - Compound body with children calculates volume correctly) - Completed" << std::endl;
	}


	SECTION("Test GetMass - Compound body with no children has zero mass")
	{
		CCompound compound;
		REQUIRE(compound.GetMass() == 0.0);
		std::cout << "Test CCompound class (GetMass - Compound body with no children has zero mass) - Completed" << std::endl;
	}

	SECTION("Test GetMass - Compound body with children calculates mass correctly")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CSphere>(1.0, 3.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCylinder>(2.0, 2.0, 2.0);

		compound.AddChild(child1);
		compound.AddChild(child2);

		double expectedMass = child1->GetMass() + child2->GetMass();
		REQUIRE(compound.GetMass() == Approx(expectedMass));
		std::cout << "Test CCompound class (GetMass - Compound body with children calculates mass correctly) - Completed" << std::endl;
	}


	SECTION("Test AddChild - Adding the same body twice throws exception")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CParallelepiped>(2.0, 2.0, 2.0, 2.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCone>(3.0, 3.0, 3.0);

		compound.AddChild(child1);
		REQUIRE_THROWS_AS(compound.AddChild(child1), std::logic_error);
		std::cout << "Test CCompound class (AddChild - Adding the same body twice throws exception) - Completed" << std::endl;
	}

	SECTION("Test AddChild - Adding different bodies does not throw exception")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CParallelepiped>(2.0, 2.0, 2.0, 2.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCone>(3.0, 3.0, 3.0);

		compound.AddChild(child1);
		REQUIRE_NOTHROW(compound.AddChild(child2));
		std::cout << "Test CCompound class (AddChild - Adding different bodies does not throw exception) - Completed" << std::endl;
	}


	SECTION("Test AppendProperties - Output stream contains correct properties")
	{
		CCompound compound;
		std::shared_ptr<CBody> child1 = std::make_shared<CParallelepiped>(2.0, 2.0, 2.0, 2.0);
		std::shared_ptr<CBody> child2 = std::make_shared<CCone>(3.0, 3.0, 3.0);

		compound.AddChild(child1);
		compound.AddChild(child2);

		std::string expectedOutput = "Составное тело\nПлотность = 2.77945839\nОбъём = 36.27433388\nМасса = 100.8230016\n";
		expectedOutput += "----------------\n";
		expectedOutput += "Дети: 2\n\n";
		expectedOutput += child1->ToString() + "\n";
		expectedOutput += child2->ToString() + "\n";

		REQUIRE(compound.ToString() == expectedOutput);
		std::cout << "Test CCompound class (AppendProperties - Output stream contains correct properties) - Completed" << std::endl;
	}
	

}