/**
 * Models a course, composed of a Department and course code.
 */
public class Course {
    /**
     * The department the course belongs to.
     */
    Department department;

    /**
     * The course code, e.g. 101.
     */
    int code;

    /**
     * Create a new course.
     * @param department {@link Course#department}
     * @param code {@link Course#code}
     */
    public Course(Department department, int code) {
        this.department = department;
        this.code = code;
    }

    /**
     * @return {@link Course#department}
     */
    public Department getDepartment() {
        return department;
    }

    /**
     * @return {@link Course#code}
     */
    public int getCode() {
        return code;
    }

    /**
     * @return A string representation of Course, currently only its code.
     * (I would include the department, but the assignment document seems to prefer otherwise).
     */
    public String toString() {
        return Integer.toString(code);
    }
}
