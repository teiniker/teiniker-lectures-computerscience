# Unified Modeling Language

The **Unified Modeling Language (UML)** is a family of graphical notations that help in 
describing and designing software systems.
UML is an open standard, controlled by the **Object Management Group (OMG)**.

Graphical modeling languages have been around in the software industry for a long time. 
The fundamental driver behind them all is that programming languages are not at a high enough level of **abstraction** 
to facilitate discussions about design.


## Why Modeling?
Engineers build models to find out if their designs will work.
This implies that **models must be testable**. If they can’t evaluate the model, the model has no value.
Engineers investigate designs with models when the **models are much cheaper than the real thing** they are building.

This is different in software engineering and the Unified Modeling Language:
* There is no firm criteria for testing a UML diagram. We can look at it (applying principles and patterns to it) but 
  this evaluation is still very subjective.
* UML diagrams are less expensive to draw than software is to write, but not by a huge factor. There are times when 
  it’s easier to change source code than to change a diagram.

## UML Diagrams Overview

UML 2 describes **13 diagram types** which can be classified in the following way:

* **Structure Diagrams**:
    * Class Diagram
    * Object Diagram
    * Component Diagram
    * Composite Structure Diagram
    * Deployment Diagram
    * Package Diagram

* **Behavior Diagrams**:
  * [Activity Diagram](UML-Activity-Diagram.md)
  * Use Case Diagram
  * State Diagram
  * Sequence Diagram
  * Communication Diagram
  * Timing Diagram

## Effective Use of UML
We can not simply use UML in the way classic engineers use blueprints and models.

When should we use UML:
* **Communicating with others**: UML is convenient for communicating design concepts among software developers.

* **Road maps**: UML can be useful for creating road maps of large software structures. 
  Such diagrams capture the knowledge that all the developers must keep in their heads in order to work effectively
  in the system.

* **What to keep and what to throw away**: Most of the UML diagrams should be short-lived.
  Write them on a white board, or on scraps of paper.
  The real useful diagrams will keep showing up over and over again.
  Keep only those whose long-term survival has lots of value.

  
## References
* Martin Fowler. **UML Distilled**. Addison-Wesley, 3rd Edition, 2004

* Robert C. Martin. **UML for Java Programmers**. Prentice Hall, 2003

* Jim Arlow, Ila Neustadt. **UML 2 and the Unified Process**. Addison-Wesley, 2nd Edition, 2005

*Egon Teiniker, 2020-2021, GPL v3.0*  


