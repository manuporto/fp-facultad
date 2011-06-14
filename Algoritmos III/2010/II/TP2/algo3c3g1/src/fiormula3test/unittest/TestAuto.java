package fiormula3test.unittest;

import junit.framework.TestCase;
import fiormula3.modelo.*;

public class TestAuto extends TestCase {

		private Auto auto;

		public void setUp() {
				auto = new Auto(new Lin64(), new Mess10());
		}
		public void tearDown() {
				auto = null;
		}

		public void testBuildCar() {
				assertFalse("New car is not null.", null == auto);
		}

		public void testSetVelocidad() {
		}
}