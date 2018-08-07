import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static final String TYPE_STRING = "<str>";
	static final String TYPE_INT = "<int>";
	static final String TYPE_PATH = "<path>";
	public static void main(String[] args) {
		int n, m;
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
//		System.out.println("n, m:" + n + ", " + m);
		List<String> ptns = new ArrayList<String>();
		List<String> targets = new ArrayList<String>();
		List<String> names = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			ptns.add(scanner.next());
//			System.out.println(ptns.get(i));
			names.add(scanner.next());
//			System.out.println(names.get(i));
		}
		for (int i = 0; i < m; i++) {
			targets.add(scanner.next());
		}
		L1: for (int j = 0; j < targets.size(); j++) {
			String target = targets.get(j);
//			System.out.println(target);
//			for (int i = 0; i < target.length(); i++) {
//				if (!((target.charAt(i) >= 'a' && target.charAt(i) <= 'z') ||
//					(target.charAt(i) >= 'A' && target.charAt(i) <= 'Z') ||
//					(target.charAt(i) >= '0' && target.charAt(i) <= '9') ||
//					target.charAt(i) == '-' ||
//					target.charAt(i) == '_' ||
//					target.charAt(i) == '.' ||
//					target.charAt(i) == '/')) {
//						System.out.println("404");
//						continue L1;
//					}
//			}
			L2: for (int p = 0; p < ptns.size(); p++) {
				String ptn = ptns.get(p);
				String outstr = names.get(p);
				String[] psegs = ptn.split("/");
				String[] tsegs = target.split("/");
				if (!ptn.contains(TYPE_PATH) && psegs.length != tsegs.length)
					continue;
//				if (!psegs[1].equals(tsegs[1]))
//					continue;
				L3: for (int i = 1; i < psegs.length; i++) {
//					System.out.println(psegs[i] + names.get(p));
					switch (psegs[i]) {
					case TYPE_PATH:
						outstr += " ";
						for (int k = i; k < tsegs.length; k++) {
							outstr += (tsegs[k] + "/");
						}
						outstr = outstr.substring(0, outstr.length() - 1);
						System.out.println(outstr);
						continue L1;
					case TYPE_STRING:
						outstr += (" " + tsegs[i]);
//						System.out.println(outstr);
						break;
					case TYPE_INT:
						try {
							int k = Integer.valueOf(tsegs[i]);
							outstr += (" " + k);
//							System.out.println(outstr);
						} catch (Exception e) {
							// TODO: handle exception
							continue L2;
						}
						break;
					default:
//						System.out.println("default: " + psegs[i] + "***" + tsegs[i]);
						if (psegs[i].equals(tsegs[i])) {
							break;
						}
						else
						continue L2;
					}
				}
				System.out.println(outstr);
				continue L1;
			}
			System.out.println("404");
		}
	}
}
