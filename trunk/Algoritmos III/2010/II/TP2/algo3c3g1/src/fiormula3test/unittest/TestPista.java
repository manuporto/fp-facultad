package fiormula3test.unittest;

import junit.framework.TestCase;
import fiormula3.modelo.*;

public class TestPista extends TestCase {

		public void testCrearPista() {
				Pista pista = new Pista(null, null, null);
				assertFalse("New Pista is not null.", null == pista);
		}
}