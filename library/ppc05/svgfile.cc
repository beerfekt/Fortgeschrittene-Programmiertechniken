/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "svgfile.h"
#include <iostream>
#include <cassert>
#include <algorithm>

#include "string.h"
#include "point44.h"
#include "math.h"

//const std::string SVGFile::header1 = R"(<?xml version="1.0" standalone="no"?>)";
//const std::string SVGFile::header2 = R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)";
////[viewbox
//const std::string SVGFile::header3 = R"(<svg xmlns="http://www.w3.org/2000/svg"  width="$w" height="$h" viewBox="$v">)";
////]
//const std::string SVGFile::footer1 = R"(</svg>)";

SVGFile::SVGFile(const std::string& filename) :
    mFile(filename)
{
    assert(mFile.is_open());
}

SVGFile::~SVGFile()
{
    assert(mFile.is_open());
    mFile << header1 << std::endl;
    mFile << header2 << std::endl;
    std::string width = std::to_string(mXMax - mXMin);
    std::string height = std::to_string(mYMax - mYMin);
    std::string actualHeader3 = header3;
    String::replace(actualHeader3, "$w", width);
    String::replace(actualHeader3, "$h", height);
    //[viewbox
    std::string viewbox = std::to_string(mXMin) + " " + std::to_string(mYMin) + " " + width + " " + height;
    String::replace(actualHeader3, "$v", viewbox);
    //]
    mFile << actualHeader3 << std::endl;
    mFile << mSVGData;
    mFile << footer1 << std::endl;
}
//[viewbox
void SVGFile::add(const Point& point)
{
    assert(mFile.is_open());
    mSVGData += point.toSVG();
    mSVGData += '\n';
    mXMax = std::max(mXMax, Math::toInt(point.getX()) + Point::svgRadius());
    mXMin = std::min(mXMin, Math::toInt(point.getX()) - Point::svgRadius());
    mYMax = std::max(mYMax, Math::toInt(point.getY()) + Point::svgRadius());
    mYMin = std::min(mYMin, Math::toInt(point.getY()) - Point::svgRadius());
}
//]
