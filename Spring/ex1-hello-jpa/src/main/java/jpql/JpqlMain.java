package jpql;


import jakarta.persistence.*;

import java.util.List;

public class JpqlMain {
	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");
		EntityManager em = emf.createEntityManager();
		//code
		EntityTransaction tx = em.getTransaction();
		tx.begin();
		try {
			Member member = new Member();
			member.setAge(10);
			member.setUsername("member1");
			em.persist(member);

			TypedQuery<Member> query1 = em.createQuery("select m from Member m", Member.class);
			Query query2 = em.createQuery("select m from Member m");




//			em.createQuery()

			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
