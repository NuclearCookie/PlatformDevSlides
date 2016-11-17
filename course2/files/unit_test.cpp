#if defined (UnitTests)
    #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
    #include "catch.hpp"
#endif
#include <sstream>
#include <string>

class Vector3 {
public:
    Vector3()
        : x(0)
        , y(0)
        , z(0)
    {}

    Vector3(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {}

    static Vector3 Add( const Vector3 & lhs, const Vector3 & rhs)
    {
        return Vector3( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z );
    }

    std::string ToString()
    {
        std::stringstream
            stream;

        stream << "[" << x << ";" << y << ";" << z << "]";

        return stream.str();
    }

public:
    float x,y,z;
};

#if defined (UnitTests)
TEST_CASE( "Vector3s are constructed correctly", "[vector3]") {
    Vector3 test_vector1;
    Vector3 test_vector2( 1, 2, 3 );

    REQUIRE( test_vector1.x == 0);
    REQUIRE( test_vector1.y == 0);
    REQUIRE( test_vector1.z == 0);

    REQUIRE( test_vector2.x == 1);
    REQUIRE( test_vector2.y == 2);
    REQUIRE( test_vector2.z == 3);
}

TEST_CASE( "Vector3s are added", "[vector3]" ) {
    Vector3 test_vector1( 20, 40, 10 );

    SECTION( "2 positive vector3s can be added", "[vector3]") {
        Vector3 test_vector2( 10, 60, 40 );
        Vector3 result;
        result = Vector3::Add(test_vector1, test_vector2);
        REQUIRE( result.x == 30 );
        REQUIRE( result.y == 100 );
        REQUIRE( result.z == 50 );
    }
    SECTION( "1 positive vector3 can be added with 0", "[vector3]") {
        Vector3 test_vector2( 0, 0, 0 );
        Vector3 result;
        result = Vector3::Add(test_vector1, test_vector2);
        REQUIRE( result.x == 20 );
        REQUIRE( result.y == 40 );
        REQUIRE( result.z == 10 );
    }
    SECTION( "1 positive vector3 can be added with a negative vector 3", "[vector3]") {
        Vector3 test_vector2( -20, -40, -10 );
        Vector3 result;
        result = Vector3::Add(test_vector1, test_vector2);
        REQUIRE( result.x == 0 );
        REQUIRE( result.y == 0 );
        REQUIRE( result.z == 0 );
    }
}

TEST_CASE("Vector3s can be printed", "[vector3]") {
    Vector3 printable_vector(1.1, 2, 5);

    REQUIRE( printable_vector.ToString() == "[1.1;2;5]");
}
#endif
