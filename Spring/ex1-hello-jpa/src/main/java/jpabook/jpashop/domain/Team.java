package jpabook.jpashop.domain;

import java.util.ArrayList;
import java.util.List;

import org.hibernate.annotations.Cascade;
import org.hibernate.annotations.CascadeType;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToMany;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
public class Team {
	@Id @GeneratedValue
	@Column(name = "TEAM_ID")
	private Long id;

	private String name;

	@OneToMany(mappedBy = "team", fetch = FetchType.LAZY)
	@Cascade(CascadeType.ALL)
	private List<Member> members = new ArrayList<>();

	public void addMember(Member member) {
		members.add(member);
		member.setTeam(this);
	}
}
