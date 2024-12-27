# Neopixel Arduino Controller
C++ code for controlling Adafruit Neopixel LEDs

## TODO

- Support Neopixel Grid
- Try virtual methods to see if they have any performance impact
- Develop virtual testing environment that doesn't need a physical LED board to test effects
  - Need separate toolchain to support this
  - Use basic text graphics to display a LED board and its colors

# Tools

## Color Generator
Takes the current time and returns a color based on some algorithm
A Rainbow generator will shift a hue value each time a color is requested

```cpp
class ColorGenerator {
public:
  virtual auto generate(long time)
  virtual ~ColorGenerator() = default;  
};
```

# Effects

## Trail Effect (Line)
Light up N number of neighboring pixels and animate them across the line T times

## Breathe Effect (Line)
Fade N number of pixels a color in and out T times at S speed