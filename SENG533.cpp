#include <iostream>    
#include <chrono>     
 
int main ()
{
	// Define variables to count transfer results
    int successfulTransfers = 0;
    int partiallySuccessfulTransfers = 0;
    int unsuccessfulTransfers = 0;
	
	// Define the duration of the client operation
    int testTimeSeconds = 100;

    // Start the timer
    auto start = std::chrono::steady_clock::now();

    // Run the client operation for 100 seconds
    while (true) {
        // Check if the operation duration has elapsed
        auto now = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if (elapsedSeconds >= testTimeSeconds) {
            break;
        }

        //Mock function for capturing and transfering photo
        int photoResult = capturePhoto();
		if(photoResult == 0){
			successfulTransfers++;
		}
		else if(photoResult == -1){
			unsuccessfulTransfers++;
		}
		else{
			partiallySuccessfulTransfers++;
		}
    }
	
	// Calculate and display transfer statistics
    std::cout << "Client operation completed." << std::endl;
    std::cout << "Successful transfers: " << successfulTransfers << std::endl;
    std::cout << "Partially successful transfers: " << partiallySuccessfulTransfers << std::endl;
    std::cout << "Unsuccessful transfers: " << unsuccessfulTransfers << std::endl;
 
    return 0;
}