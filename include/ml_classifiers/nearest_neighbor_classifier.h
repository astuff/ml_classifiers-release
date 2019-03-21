/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Scott Niekum
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************/

#ifndef ML_CLASSIFIERS_NEAREST_NEIGHBOR_CLASSIFIER_H
#define ML_CLASSIFIERS_NEAREST_NEIGHBOR_CLASSIFIER_H

#include "ml_classifiers/classifier.h"

#include <map>
#include <string>
#include <vector>

namespace ml_classifiers
{

using CPoint = std::vector<double>;
using CPointList = std::vector<CPoint>;
using ClassMap = std::map<std::string, CPointList>;

class NearestNeighborClassifier : public Classifier
{
public:
  ClassMap class_data;

  NearestNeighborClassifier();
  ~NearestNeighborClassifier();

  void save(const std::string filename);
  bool load(const std::string filename);
  void addTrainingPoint(std::string target_class, const std::vector<double> point);
  void train();
  void clear();
  std::string classifyPoint(const std::vector<double> point);
};

}  // namespace ml_classifiers

#endif  // ML_CLASSIFIERS_NEAREST_NEIGHBOR_CLASSIFIER_H
