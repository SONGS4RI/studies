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


			List<Member> members = em.createQuery("select m from Member m", Member.class).getResultList();
			Member findMember = members.get(0);
			findMember.setUsername("changed");
			
			List<Team> teams = em.createQuery("select t from Member m join m.team t", Team.class).getResultList();

			// dto 로 뽑기
			List<MemberDto> resultList = em.createQuery("select new jpql.MemberDto(m.username, m.age) from Member m", MemberDto.class)
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
