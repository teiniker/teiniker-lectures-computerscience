# Logging Frameworks

Logging frameworks provide developers with a structured way to **record events, 
messages, and errors** that occur during the execution of a program. 

These frameworks are designed to facilitate **debugging**, **monitoring**, 
and analysis of software behavior. 

Here are some key aspects of logging frameworks in C:

* **Logging Levels**: Logging frameworks typically support multiple levels of 
    logging, such as DEBUG, INFO, WARNING, ERROR, and FATAL. Each level corresponds 
    to the severity of the message being logged, allowing developers to filter 
    messages based on their importance.

* **Log Messages**: Log messages often include timestamps, thread/process IDs, 
    and additional context information to aid in debugging and analysis.

* **Output Destinations**: Logging frameworks support various output destinations, 
    such as console output, log files, network streams, databases, and custom sinks. 
    Developers can configure the logging framework to send log messages to one or 
    more destinations based on their requirements.    

* **Formatting and Filtering**: Logging frameworks provide facilities for formatting 
    log messages and applying filters to control which messages are logged based on 
    criteria such as logging level, message content, or source location. This allows 
    developers to tailor logging behavior to suit different deployment environments 
    and debugging scenarios.

* **Configuration**: Logging frameworks typically support configuration options that 
    allow developers to customize logging behavior dynamically at runtime. 
    Configuration options may include log levels, output destinations, log message 
    formats, and logging filters. Some frameworks also support external configuration 
    files to simplify deployment and management.    

Logging frameworks can be integrated into existing C codebases with minimal effort. 
They often provide APIs and macros for logging messages from different parts of the 
application, making it easy to instrument code for logging purposes. 

Additionally, logging frameworks may offer integration with other tools and libraries 
commonly used in C development, such as unit testing frameworks and build systems.

_Example:_ Using logging for debugging
```C
int data_read(char *filename, double data[], size_t size)
{
    log_debug("data_read(\"%s\", %p, %ld)", filename, data, size);
    //...
}
```

_Example:_ Logging console output
```
13:10:01 DEBUG read-data.c:24: main()
13:10:01 DEBUG read-data.c:47: data_read("measurement.txt", 0x7fffc9c693c0 10)
13:10:01 DEBUG read-data.c:66: data_print(0x7fffc9c693c0, 10)
```


## References

* [log.c](https://github.com/rxi/log.c)

*Egon Teiniker, 2020-2024, GPL v3.0* 