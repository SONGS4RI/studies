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

			em.createQuery("select m from Member m order by m.age desc", Member.class)
					.setFirstResult(0)
					.setMaxResults(10)
					.getResultList();

			

			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
