#pragma once

struct ColorA {
    float R, G, B, A;
};

struct iColor {
    unsigned int R, G, B;
};

struct fColor {
    float R, G, B;
};

inline const fColor Black  = {0.0f, 0.0f, 0.0f};
inline const fColor White  = {1.0f, 1.0f, 1.0f};
inline const fColor Red    = {1.0f, 0.0f, 0.0f};
inline const fColor Green  = {0.0f, 1.0f, 0.0f};
inline const fColor Blue   = {0.0f, 0.0f, 1.0f};
inline const fColor Yellow = {1.0f, 1.0f, 0.0f};
