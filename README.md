# TempSense: Smart Temperature Prediction with DHT11, NodeMCU, and Random Forest Regression

TempSense is a project that utilizes a DHT11 sensor, NodeMCU microcontroller, and machine learning techniques to fetch temperature data, store it in a spreadsheet, and make intelligent predictions using Random Forest Regression. This README provides an overview of the project's flow, setup, and functionality.

## Project Flow

1. **Data Collection**
   - The NodeMCU microcontroller is connected to the DHT11 sensor, which enables it to collect real-time temperature data from the surrounding environment.
   - The nodemcu code (found in the "nodemcu" file) implements the necessary logic to read data from the DHT11 sensor and format it for further processing.

2. **Data Transmission**
   - Once the temperature data is collected by the NodeMCU, it uses an API and script to send this data to a designated spreadsheet or data storage service.
   - The API and script act as an intermediary, taking the data from the NodeMCU and forwarding it to the spreadsheet for storage.

3. **Data Storage**
   - The temperature data is stored in the spreadsheet, creating a historical record of the collected values over time.
   - The spreadsheet serves as the dataset that will be used to train and test the machine learning model.

4. **Machine Learning**
   - The "ML on iot_data" file contains the code for the machine learning aspect of the project.
   - Random Forest Regression is used as the machine learning algorithm due to its ability to handle non-linear relationships and provide accurate predictions for numerical data like temperature.
   - The dataset collected in the spreadsheet is preprocessed and split into training and testing sets.
   - The Random Forest Regression model is trained using the training data to learn the patterns and relationships between temperature data and other features, if any.
   - After training, the model is tested on the test dataset to evaluate its predictive performance.

5. **Temperature Prediction**
   - With the trained Random Forest Regression model, the system can now make temperature predictions based on new input data.
   - By feeding new data into the trained model, the system can forecast temperature values with a reasonable level of accuracy.

## Setup Instructions

1. Hardware Setup:
   - Connect the DHT11 sensor to the NodeMCU as per the specified pin configurations.
   - Ensure the NodeMCU is properly connected to a power source and can access the internet to send data to the spreadsheet.

2. Spreadsheet and API Setup:
   - Create a new spreadsheet or use an existing one where the temperature data will be stored.
   - Set up an API and script to receive data from the NodeMCU and append it to the spreadsheet.

3. Machine Learning Setup:
   - Install the necessary libraries and dependencies for the machine learning code.
   - Ensure the dataset from the spreadsheet is available and formatted correctly for training and testing the model.

4. Running the Project:
   - Upload the "nodemcu" code to the NodeMCU microcontroller.
   - Execute the machine learning code ("ML on iot_data") to train the Random Forest Regression model and make temperature predictions.

## Conclusion

TempSense is a practical and intelligent system for fetching real-time temperature data, storing it in a spreadsheet, and utilizing machine learning techniques to predict temperature values. The project can have various applications in weather monitoring, home automation, and environmental sensing. By following the setup instructions, you can set up your own TempSense system and explore the fascinating world of Internet of Things (IoT) and machine learning for temperature prediction. Happy coding!
