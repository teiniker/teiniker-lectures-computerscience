# Jenkins 

> Jenkins is an **open-source automation server** used mainly for 
> **continuous integration (CI)** and **continuous delivery (CD)**.


## Setup Jenkins 

A **WAR (Web Application Archive)** is a Java web application packaged for 
deployment. The Jenkins WAR can be run directly with a compatible Java 
runtime (for example, JDK 21) using `java -jar jenkins.war`, so we can 
start Jenkins without installing a separate application server.

* Download Jenkins Generic Java package (.war): [https://www.jenkins.io/download/](https://www.jenkins.io/download/) 

* In the download directory
    ```bash
    $ java -jar jenkins.war --httpPort=8080
    ```

* Browse to http://localhost:8080

* Follow the instructions to complete the installation
  - Enter intital password (see command line output)
  - Install plugins
  - Enter username and password 

## Jenkins Plugins 

After Jenkins setup, we can add functionality by installing plugins.

On the Jenkins web page, navigate to:

* Manage Jenkins 
  - Plugins
    - Available plugins: `<plugin-name>`


### HTML Publisher

The **HTML Publisher** plugin, can be used to show
generated Doxygen documentation as part of the pipeline report.


## Jenkins Pipeline Examples

These examples are implemented in different **GitHub repositories**
to show us some concrete examples of how to setup a Jenkins pipeline
for different programming languages:

* [Jenkins Pipeline C](https://github.com/teiniker/jenkins-pipeline-c)

* [Jenkins Pipeline C++](https://github.com/teiniker/jenkins-pipeline-cxx)


## References

* Jenkins
    - [YouTube: How to Install Jenkins](https://youtu.be/CEyfsQq3QEM)
    - [YouTube: Complete Jenkins Pipeline Tutorial](https://youtu.be/7KCS70sCoK0)
    - [Getting started with Pipeline](https://www.jenkins.io/doc/book/pipeline/getting-started/)
    - [Jenkins](https://www.jenkins.io/)
    - [Using a Jenkinsfile](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/)

* Jenkins Plugins
    - [HTML Publisher](https://plugins.jenkins.io/htmlpublisher/)

*Egon Teiniker, 2024-2026, GPL v3.0* 
