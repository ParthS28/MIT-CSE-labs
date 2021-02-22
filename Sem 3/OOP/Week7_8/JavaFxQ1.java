// Write a JavaFX application program to do the following: 
// Display the message “Welcome to JavaFX programming” using Label in the Scene. 
// Set the text color of the Label to Magenta. 
// Set the title of the Stage to “This is the first JavaFX Application”.
// Set the width and height of the Scene to 500 and 200 respectively. 
// Use FlowPane layout and set the hgap and vgap of the FlowPane to desired values. 
// The program will accept an integer from the user in a text field  and 
// display the multiplication table (up to number *10) for that number. 

import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.Color;

 

public class JavaFxQ1 extends Application
{
    public static void main(String args[])
    {
        launch(args);
    }
    public void start(Stage myStage)
    {
        myStage.setTitle("This is the first JavaFX application"); 
        FlowPane rootnode= new FlowPane();
        rootnode.setHgap(200);
        rootnode.setVgap(100);

 

        Scene myScene=new Scene(rootnode,500,200); 
        myStage.setScene(myScene); 
        
        Label label=new Label("Welcome to javafx programming");
        label.setTextFill(Color.MAGENTA);
    rootnode.getChildren().add(label); myStage.show();
    }
}