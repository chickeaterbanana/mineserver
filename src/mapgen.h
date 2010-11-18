/*
  The MIT License

  Copyright (c) 2009, 2010 Matvei Stefarov <me@matvei.org>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#ifndef _MAPGEN_H
#define _MAPGEN_H

#include "mapgenargs.h"
#include "noise.h"

enum MapGenTemplate {
  Archipelago,
  Atoll,
  Bay,
  Default,
  Dunes,
  Flat,
  Hills,
  Ice,
  Island,
  Lake,
  Mountains,
  Peninsula,
  River,
  Streams
};

class MapGen
{
private:
  MapGenArgs args;
  Noise noise;
  float** heightmap;
  float** blendmap;
  float** slopemap;
  
  Block bWaterSurface, bGroundSurface, bWater, bGround, bSeaFloor, bBedrock, bDeepWaterSurface, bCliff;

  const int WaterCoveragePasses;
  const float CliffsideBlockThreshold;
  
  int groundThickness, seaFloorThickness;
  
  struct WaterParticle 
  {
      int x, y, h;
      float velocity, mass, deposit;
  };
public:
  MapGen(MapGenArgs mArgs);
  
  void GenerateHeightmap();
  void applyBias();
  
  float MatchWaterCoverage(float** heightmap, float desiredWaterCoverage);
  float CalculateWaterCoverage(float** heightmap, float waterLevel);
  void CalculateSlope(float** heightmap, float** slopemap);

  void applyTheme( MapGenTheme theme );

  //void Erode();

};


#endif
