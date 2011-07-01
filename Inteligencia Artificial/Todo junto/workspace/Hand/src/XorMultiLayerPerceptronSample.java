import org.neuroph.core.NeuralNetwork;
import org.neuroph.nnet.MultiLayerPerceptron;
import org.neuroph.core.learning.TrainingSet;
import org.neuroph.core.learning.TrainingElement;
import org.neuroph.core.learning.SupervisedTrainingElement;
import java.util.Vector;
import org.neuroph.util.TransferFunctionType;

/**
* This sample shows how to create, train, save and load simple Multi Layer Perceptron
*/
public class XorMultiLayerPerceptronSample {

    public static void main(String[] args) {

        // create training set (logical XOR function)
        TrainingSet trainingSet = new TrainingSet();
        trainingSet.addElement(new SupervisedTrainingElement(new double[]{0, 0}, new double[]{0}));
        trainingSet.addElement(new SupervisedTrainingElement(new double[]{0, 1}, new double[]{1}));
        trainingSet.addElement(new SupervisedTrainingElement(new double[]{1, 0}, new double[]{1}));
        trainingSet.addElement(new SupervisedTrainingElement(new double[]{1, 1}, new double[]{0}));

        // create multi layer perceptron
        MultiLayerPerceptron myMlPerceptron = new MultiLayerPerceptron(TransferFunctionType.TANH, 2, 3, 1);
        // learn the training set
        myMlPerceptron.learnInSameThread(trainingSet);

        // test perceptron
        System.out.println("Testing trained neural network");
        testNeuralNetwork(myMlPerceptron, trainingSet);

        // save trained neural network
        myMlPerceptron.save("myMlPerceptron.nnet");

        // load saved neural network
        NeuralNetwork loadedMlPerceptron = NeuralNetwork.load("myMlPerceptron.nnet");

        // test loaded neural network
        System.out.println("Testing loaded neural network");
        testNeuralNetwork(loadedMlPerceptron, trainingSet);

    }

    public static void testNeuralNetwork(NeuralNetwork nnet, TrainingSet tset) {

        for(TrainingElement trainingElement : tset.trainingElements()) {

            nnet.setInput(trainingElement.getInput());
            nnet.calculate();
            Vector<Double> networkOutput = nnet.getOutput();
            System.out.print("Input: " + trainingElement.getInput());
            System.out.println(" Output: " + networkOutput);

        }

    }

}