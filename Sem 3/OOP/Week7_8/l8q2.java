// Write a JavaFX program to display a window as shown below. 
// Use TextField for UserName and PasswordField for Password input. 
// On click of “Sign in” Button the message “Welcome UserName” should be displayed in a Text Control. 
// Use GridPane layout for the application

import java.util.*;
import javafx.application.*;
import javafx.scene.control.*;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.event.*;
import javafx.scene.paint.Color;
import javafx.geometry.*;

public class l8q2 extends Application{
	public void start(Stage myStage){

		myStage.setTitle("JavaFX Welcome");

		GridPane rootNode= new GridPane();

		myStage.setTitle("Welcome");

		rootNode.setAlignment( Pos.CENTER );
		Label response =new Label();
		Scene myScene = new Scene( rootNode, 300, 200 );
		Label label1= new Label();
		Label label2= new Label();
		Label label3= new Label();
		label1.setText("UserName");
		label2.setText("Password");

		TextField textField= new TextField();

		PasswordField passwordField = new PasswordField();

		textField.setPromptText("User Name");

		passwordField.setPromptText("Password");

		Button btn1=new Button("Sign In");
		 

		btn1.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
			label3.setText("Welcome "+textField.getText());
			}
		});
		rootNode.add(label1, 0, 0, 1, 1);
		rootNode.add(label2, 0, 1, 1, 1);
		rootNode.add(textField, 1, 0, 1, 1);
		rootNode.add(passwordField, 1, 1, 1, 1);
		rootNode.add(label3, 0, 2, 1, 1);
		rootNode.add(btn1, 1, 2, 1, 1);

		myStage.setScene(myScene);
		myStage.show();
		}

		public static void main(String args[]){
			launch(args);
	}
}