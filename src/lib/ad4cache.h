/*

   Copyright (c) 2006-2010, The Scripps Research Institute

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   Author: Dr. Oleg Trott <ot14@columbia.edu>, 
           The Olson Lab, 
           The Scripps Research Institute

*/

#include <string>
#include "igrid.h"
#include "grid.h"
#include "model.h"
#include "file.h"

struct ad4cache : public igrid {
    ad4cache() {}
	ad4cache(fl slope_);
	fl eval      (const model& m, fl v) const; // needs m.coords // clean up
	fl eval_intra(      model& m, fl v) const; // needs m.coords, sets m.minus_forces // clean up
	fl eval_deriv(      model& m, fl v) const; // needs m.coords, sets m.minus_forces // clean up
    grid_dims read(const std::string& str);
    void write(const std::string& out_prefix, const szv& atom_types, const std::string& gpf_filename="NULL",
               const std::string& fld_filename="NULL", const std::string& receptor_filename="NULL");
private:
	std::string scoring_function_version;
	atomv atoms; // for verification
	grid_dims gd;
	fl slope; // does not get (de-)serialized
	atom_type::t atu;
	std::vector<grid> grids;
};
