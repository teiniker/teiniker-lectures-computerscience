# LaTex Formulars in MD Files 


## Introduction
This document describes how to include LaTex formulars in markdown files.

Write LaTeX using `$...$` (inline) or `$$...$$` (block).

_Example:_ Inline formular - Euler's identity: $e^{i\pi} + 1 = 0$

_Example:_ Block formular - Fundamental theorem of calculus:

$$
\frac{d}{dx} \int_{a}^{x} f(t)dt = f(x)
$$


## Examples

| Formula                      | LaTeX code                     |
| ---------------------------- | ------------------------------ |
| $a+b$                        | `$a+b$`                        |
| $a-b$                        | `$a-b$`                        |
| $a\cdot b$                   | `$a\cdot b$`                   |
| $a\times b$                  | `$a\times b$`                  |
| $\frac{a}{b}$                | `$\frac{a}{b}$`                |
| $a^2$                        | `$a^2$`                        |
| $a^n$                        | `$a^n$`                        |
| $\sqrt{x}$                   | `$\sqrt{x}$`                   |
| $\sqrt[n]{x}$                | `$\sqrt[n]{x}$`                |
| $a=b$                        | `$a=b$`                        |
| $a\neq b$                    | `$a\neq b$`                    |
| $a<b$                        | `$a<b$`                        |
| $a\le b$                     | `$a\le b$`                     |
| $a>b$                        | `$a>b$`                        |
| $a\ge b$                     | `$a\ge b$`                     |
| $x_1$                        | `$x_1$`                        |
| $x_{ij}$                     | `$x_{ij}$`                     |
| $\left(a+b\right)$           | `$\left(a+b\right)$`           |
| $\frac{x+1}{y-1}$            | `$\frac{x+1}{y-1}$`            |
| $\lvert x\rvert$             | `$\lvert x\rvert$`             |
| $\sum_{i=1}^{n} i$           | `$\sum_{i=1}^{n} i$`           |
| $\prod_{i=1}^{n} i$          | `$\prod_{i=1}^{n} i$`          |
| $\int_a^b f(x),dx$           | `$\int_a^b f(x)\,dx$`          |
| $\lim_{x\to\infty} f(x)$     | `$\lim_{x\to\infty} f(x)$`     |
| $\sin (x)$                   | `$\sin (x)$`                   |
| $\cos x$                     | `$\cos x$`                     |
| $\tan x$                     | `$\tan x$`                     |
| $\log x$                     | `$\log x$`                     |
| $\ln x$                      | `$\ln x$`                      |
| $e^x$                        | `$e^x$`                        |
| $\alpha, \beta, \gamma, \pi$ | `$\alpha, \beta, \gamma, \pi$` |
| $\infty$                     | `$\infty$`                     |
| $\pm x$                      | `$\pm x$`                      |
| $a\in A$                     | `$a\in A$`                     |
| $A\subset B$                 | `$A\subset B$`                 |
| $A\cup B$                    | `$A\cup B$`                    |
| $A\cap B$                    | `$A\cap B$`                    |
| $\forall x \in A$            | `$\forall x \in A$`            |
| $\exists x \in A$            | `$\exists x \in A$`            |


## Setup 

To include LaTex formulars in markdown files, you need to install the following extension in VS Code:

![Markdown+Math](figures/VSCodeExtension-Math.png)


## References

* [LaTex Mathematical Symbols (Cheat Sheet)](figures/latex-symbols.pdf)

* [LaTeX for Students – A Simple Quickstart Guide](https://youtu.be/lgiCpA4zzGU?si=X_E8km-zwqy9oksj)
* [Learn LaTeX in 30 minutes](https://www.overleaf.com/learn/latex/Learn_LaTeX_in_30_minutes)

* [VS Code Extension: Markdown+Math](https://marketplace.visualstudio.com/items?itemName=goessner.mdmath)

*Egon Teiniker, 2020-2025, GPL v3.0* 
