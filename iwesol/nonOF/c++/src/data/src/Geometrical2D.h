/*---------------------------------------------------------------------------*\
                               |
  _____        _______ ____    | IWESOL: IWES Open Library
 |_ _\ \      / / ____/ ___|   |
  | | \ \ /\ / /|  _| \___ \   | Copyright: Fraunhofer Institute for Wind
  | |  \ V  V / | |___ ___) |  | Energy and Energy System Technology IWES
 |___|  \_/\_/  |_____|____/   |
                               | http://www.iwes.fraunhofer.de
                               |
-------------------------------------------------------------------------------
License
    This file is part of IWESOL.

    IWESOL is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IWESOL is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with IWESOL.  If not, see <http://www.gnu.org/licenses/>.

Class

Description

SourceFiles

References

\*---------------------------------------------------------------------------*/

#ifndef GEOMETRICAL2D_H_
#define GEOMETRICAL2D_H_

#include <cmath>

namespace jlib{

class Geometrical2D{

public:

	/// Constructor.
	Geometrical2D(){}

	virtual ~Geometrical2D(){}

	/// Rotation by an angle in radiant.
	virtual void rotate(double angleRad){
		rotate(std::cos(angleRad),std::sin(angleRad));
	}

	/// Rotation by an cos/sin of angle.
	virtual void rotate(double cosval, double sinval) = 0;

	/// Cartesian translation.
	virtual void translate(double delta_x,double delta_y) = 0;

	/// Rescaling by a factor.
	virtual void rescale(double factor) = 0;

};

}

#endif /* GEOMETRICAL2D_H_ */
