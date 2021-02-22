
import java.util.*;
import javafx.application.*;
import javafx.scene.control.*;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.event.*;
import javafx.scene.paint.Color;
import javafx.geometry.*;

 

public class l8q1f extends Application
{
    public void start(Stage myStage)
    {
        myStage.setTitle("Multiplication table generator");
        FlowPane rootNode = new FlowPane(Orientation.VERTICAL,10,10);
        rootNode.setAlignment( Pos.CENTER );
        Label response = new Label();
        Scene myScene = new Scene( rootNode, 500, 300 );
        TextField tf = new TextField();
        tf.setPromptText("Enter multiplicant");
        tf.setOnAction(new EventHandler<ActionEvent>()
        {
            public void handle(ActionEvent ae)
            {
                final String resp=Multiply.calculate(Integer.parseInt(tf.getText()));
                response.setText(resp);
            }
        }
        );

 

        rootNode.getChildren().addAll(tf,response);
        myStage.setScene( myScene);
        myStage.show();      
    }
    public static void main(String args[])
    {
        launch(args);
    }
}

 

class Multiply 
{
    int a;
    static String calculate(int a)
    {
        String s = new String();
        for(int i = 1; i < 11; i++)
        {
            s = s + "\n";
            s= s+ a + "*" +i + "="+ a*i;                                                  
        }
        return s;
    }
}