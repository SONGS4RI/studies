// package hellojpa;
//
// import java.util.List;
//
// import jakarta.persistence.*;
//
// public class JpaMain {
//
//     public static void main(String[] args) {
//
//         EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");
//         EntityManager em = emf.createEntityManager();
//         //code
//         EntityTransaction tx = em.getTransaction();
//         tx.begin();
//         try {
//             Member m = new Member();
//             m.setUsername("a");
//             m.setRoleType(RoleType.ADMIN);
//
//             // identity일때는 id값을 알아야 하기때문에 persist할때 예외적으로 쿼리가 나간다.
//             em.persist(m);
//             tx.commit();
//         } catch (Exception e) {
//             tx.rollback();
//         } finally {
//             em.close();
//         }
//
//         emf.close();
//     }
// }
