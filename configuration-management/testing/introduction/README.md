# Introduction to Test Automation

To implement automated tests, we use a **testing framework** like **Unity**. 

Most frameworks are based on **xUnit** patterns and provide a common 
set of features, such as test discovery, setup/teardown hooks, 
assertions, and reporting. 

This consistency makes tests easier to write, run, and maintain across 
different languages and tools.

Each automated test is represented by a **test function** that implements 
a single **four-phase procedure**:

* **Setup**: We set up the test fixture that is required for the SUT to exhibit the expected behavior as well as anything we need to put in place to be able to observe the actual outcome.

* **Exercise**: We interact with the SUT.

* **Verify**: We do whatever is necessary to determine whether the expected outcome has been obtained.

* **Teardown**: We tear down the test fixture to put the world back into the state in which we found it.


## References
* Gerard Meszaros. **xUnit Test Patterns**. Addison-Wesley, 2007 
* [XUnit Basics](http://xunitpatterns.com/XUnitBasics.html)

* [Unity: Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md)
* [Unity: Assertions Reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
 
*Egon Teiniker, 2020-2026, GPL v3.0* 