





//#################################### static


#include <string>

//Ort: irgendwo... main z.b:



//Std String:

    string svg = " \"somestring\" \n";
           svg += "someotherstring";

    //output: "somestring"
    //         someotherstring


    string s2 = " cx=\"" + to_string(Math::toInt(x)) +  "\"";
    string s3 = " cy=\"" +to_string(Math::toInt(y)) +  "\"";
    svg2 += s1+s2;

    //output: cx="3s" cy="3"


//C String:

   cstring = R"( string )";
